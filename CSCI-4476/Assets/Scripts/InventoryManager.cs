using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEditor.ShaderGraph.Internal;
using UnityEngine;
using UnityEngine.UI;

public class InventoryManager : MonoBehaviour
{
    public static InventoryManager          instance;
    [SerializeField]    Transform           cameraPos;
    [SerializeField]    TextMeshProUGUI     currencyText;
    [SerializeField]    Image[]             inventorySlots;
    [SerializeField]    float               dropDistance            =   2f;
    [SerializeField]    float               throwForce              =   1000f;
                        GameObject[]        inventoryItems;
                        uint                maxInventorySlots       =   3;
                        int                 currentlySelectedSlot   =   0;
                        int                 currencyCount           =   0;
                        Vector3             headOffset;
                        Vector3             rightHandOffset;
    [SerializeField]    AudioSource         audioPlayer;
    [SerializeField]    Sprite              defaultSprite;
    [SerializeField]    Transform[]         equipmentSlots;
    [SerializeField]    GameObject[]        equipmentGameObj;


    void OnValidate(){
        if (inventorySlots.Length > maxInventorySlots){
            Debug.LogError("Too many slots serialized!", gameObject);
        }
    }

    void OnEnable(){
        InputManager.inventoryAction += SelectInventorySlot;
        InputManager.dropAction += DropItem;
        InputManager.mainAction += DoMainAction;
        InputManager.secondAction += DoSecondAction;
    }

    void OnDisable(){
        InputManager.inventoryAction -= SelectInventorySlot;
        InputManager.dropAction -= DropItem;
        InputManager.mainAction -= DoMainAction;
        InputManager.secondAction -= DoSecondAction;

    }

    void Awake(){
        if (!instance) {
            instance = this;
            inventoryItems = new GameObject[3];
            equipmentGameObj = new GameObject[equipmentSlots.Length];
            SelectInventorySlot(0);
        } 
        else Destroy(gameObject);
    }

    public bool Pickup(GameObject obj){
        PickupSO pickup = obj.GetComponent<Pickupable>().getSO();
        
        switch (pickup){
            case CurrencySO:
                // add to counter
                obj.SetActive(false);
                return PickupCurrency((CurrencySO) pickup);
            case ItemSO:
                // add to inventory
                obj.SetActive(false);
                return PickupItem(obj);
            case EquipmentSO:
                // add to player
                return PickupEquipment(obj, (EquipmentSO) pickup);
            default:
                return false;
        }
    }

    bool PickupCurrency(CurrencySO pickup){
        currencyCount += (int) pickup.value;
        audioPlayer.PlayOneShot(pickup.pickupSound);
        currencyText.text = currencyCount.ToString();
        return true;
    }
    
    bool PickupItem(GameObject pickup){
        if (inventoryItems[currentlySelectedSlot] == null){
            AddItemToSlot(pickup, currentlySelectedSlot);
            return true;
        }
        else {
            for (int i = 0; i < maxInventorySlots; i++){
                if (inventoryItems[i] == null){
                    AddItemToSlot(pickup, i);
                    return true;
                }
            }
        }
        DropItem();
        AddItemToSlot(pickup, currentlySelectedSlot);
        return true; // make false if you do not want to pickup item
    }

    void AddItemToSlot(GameObject pickup, int slot){
        // inventorySlots[slot].text = (slot + 1) + ". " + pickup.name;
        inventoryItems[slot] = pickup;
        inventorySlots[slot].sprite = ((ItemSO)pickup.GetComponent<Pickupable>().getSO()).displaySprite;
        if (slot == currentlySelectedSlot) inventorySlots[slot].color = Color.green;
        else inventorySlots[slot].color = Color.white;
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
        pickup.transform.rotation = equipmentSlots[slot].rotation;//Quaternion.identity;
        return true;
    }

    void EnablePhysics(GameObject obj){
        Rigidbody rig = obj.GetComponent<Rigidbody>();
        rig.useGravity = true;
        rig.isKinematic = false;
        obj.GetComponent<Collider>().enabled = true;
    }
    void DisablePhysics(GameObject obj){
        Rigidbody rig = obj.GetComponent<Rigidbody>();
        rig.useGravity = false;
        rig.isKinematic = true;
        obj.GetComponent<Collider>().enabled = false;
    }

    void DoMainAction(){
        int slot = (int)EquipmentSO.EquipmentSlots.RIGHTHAND;
        if (equipmentGameObj[slot] != null){
            Rigidbody rig = equipmentGameObj[slot].GetComponent<Rigidbody>();
            DropEquipment((int)EquipmentSO.EquipmentSlots.RIGHTHAND);
            rig.AddForce( cameraPos.forward * throwForce);
        }
    }
    void DoSecondAction(){
        int slot = (int)EquipmentSO.EquipmentSlots.LEFTHAND;
        if (equipmentGameObj[slot] != null){
            Rigidbody rig = equipmentGameObj[slot].GetComponent<Rigidbody>();
            DropEquipment((int)EquipmentSO.EquipmentSlots.LEFTHAND);
            rig.AddForce( cameraPos.forward * throwForce);
        }
    }

    void SelectInventorySlot(int index){
        if (inventoryItems[currentlySelectedSlot] == null) 
            inventorySlots[currentlySelectedSlot].color = Color.clear;
        else
            inventorySlots[currentlySelectedSlot].color = Color.white;
        currentlySelectedSlot = index;
        inventorySlots[currentlySelectedSlot].color = Color.green;
    }

    void DropItem(){
        if(inventoryItems[currentlySelectedSlot] != null){
            GameObject currentItem = inventoryItems[currentlySelectedSlot];
            MoveDroppedObj(currentItem);
            // inventorySlots[currentlySelectedSlot].text = currentlySelectedSlot + ". Empty";
            inventorySlots[currentlySelectedSlot].sprite = null;
            inventorySlots[currentlySelectedSlot].color = new Color(0, 0, 0, 0);
            inventoryItems[currentlySelectedSlot] = null;
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
}
