using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEditor.ShaderGraph.Internal;
using UnityEngine;
using UnityEngine.UI;
// TODO make three inventory scripts

public class InventoryManager : MonoBehaviour
{
    public static InventoryManager          instance;
    [SerializeField]    Transform           cameraPos;
    [SerializeField]    float               dropDistance            =   2f;
    public              GameObject          inventoryItem;
    public              int                 currencyCount           =   0;
    
    // head, feet, torso, lefthand, righthand
    public    Transform[]         equipmentSlots;
    public    GameObject[]        equipmentGameObj;


    void OnEnable(){
        InputManager.dropAction += DropItem;
        InputManager.mainAction += DoMainAction;
        InputManager.mainActionCancel += CancelMainAction;
    }

    void OnDisable(){
        InputManager.dropAction -= DropItem;
        InputManager.mainAction -= DoMainAction;
        InputManager.mainActionCancel -= CancelMainAction;
    }

    void Awake(){
        if (!instance) {
            instance = this;
            equipmentGameObj = new GameObject[equipmentSlots.Length];
        } 
        else Destroy(gameObject);
    }

    public bool Pickup(GameObject obj){
        PickupSO pickup = obj.GetComponent<Pickupable>().getSO();
        switch (pickup){
            case ItemSO:
                // add to inventory
                return PickupItem(obj);
            case EquipmentSO:
                // add to player
                return PickupEquipment(obj, (EquipmentSO) pickup);
            default:
                return false;
        }
    }
    
    bool PickupItem(GameObject pickup){
        pickup.SetActive(false);
        if (inventoryItem == null){
            inventoryItem = pickup;
            return true;
        }
        DropItem();     // otherwise add the pickup to the current selected slot by dropping currently held item
        inventoryItem = pickup;
        return true; 
    }

    bool PickupEquipment(GameObject pickup, EquipmentSO so){
        int slot = (int)so.slot;
        if(equipmentGameObj[slot] != null){
            DropEquipment(slot);
        }
        equipmentGameObj[slot] = pickup;
        DisablePhysics(equipmentGameObj[slot]);
        pickup.transform.parent = equipmentSlots[slot];
        pickup.transform.position = equipmentSlots[slot].position;
        pickup.transform.rotation = equipmentSlots[slot].rotation * Quaternion.Euler(so.rotOffset); //Quaternion.identity;

        return true;
    }

     void DoMainAction(){
        int slot = (int)EquipmentSO.EquipmentSlots.RIGHTHAND;
        IActionable action = equipmentGameObj[slot]?.GetComponent<IActionable>();
        if (action != null) action.StartAction();
    }

    void CancelMainAction(){
        int slot = (int)EquipmentSO.EquipmentSlots.RIGHTHAND;
        IActionable action = equipmentGameObj[slot]?.GetComponent<IActionable>();
        if (action != null) action.StopAction();
    }

    void DropItem(){
        if(inventoryItem != null){
            MoveDroppedObj(inventoryItem);
            inventoryItem = null;
        }
    }

    void DropEquipment(int slot){
        equipmentGameObj[slot].transform.parent = null;
        EnablePhysics(equipmentGameObj[slot]);
        MoveDroppedObj(equipmentGameObj[slot]);
        equipmentGameObj[slot] = null;
    }

    void MoveDroppedObj(GameObject obj){
        obj.transform.SetPositionAndRotation(cameraPos.position + Vector3.up + cameraPos.transform.forward * dropDistance, Quaternion.identity);
        obj.SetActive(true);
    }

    void EnablePhysics(GameObject obj){
        Rigidbody rig = obj.GetComponent<Rigidbody>();
        // rig.useGravity = true;
        rig.isKinematic = false;
        obj.GetComponent<Collider>().enabled = true;
    }
    void DisablePhysics(GameObject obj){
        Rigidbody rig = obj.GetComponent<Rigidbody>();
        // rig.useGravity = false;
        rig.isKinematic = true;
        obj.GetComponent<Collider>().enabled = false;
    }
}
