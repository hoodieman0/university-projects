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
                        GameObject          headEquipment;  // could make this an array of gameObjects, then dedicate position to head, etc.
                        GameObject          feetEquipment;
                        GameObject          torsoEquipment;
                        GameObject          leftHandEquipment;
                        GameObject          rightHandEquipment;
                        uint                maxInventorySlots       =   3;
                        int                 currentlySelectedSlot   =   0;
                        int                 currencyCount           =   0;
                        Vector3             headOffset;
                        Vector3             rightHandOffset;
    [SerializeField]    AudioSource         audioPlayer;


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
            SelectInventorySlot(0);
        } 
        else Destroy(gameObject);
    }


    void Update(){
        // can I do this with the observers?
        if (headEquipment) {
            headEquipment.transform.position = cameraPos.position + cameraPos.up + headOffset;
            headEquipment.transform.rotation = cameraPos.rotation;
        }
        if (feetEquipment) {
            feetEquipment.transform.rotation = cameraPos.rotation;
        }
        if (torsoEquipment) {
            // torsoEquipment.transform.rotation = cameraPos.rotation;
            
        }
        if (leftHandEquipment) {
            leftHandEquipment.transform.rotation = cameraPos.rotation;
        }
        if (rightHandEquipment) {
            rightHandEquipment.transform.position = Camera.main.transform.position + (Camera.main.transform.forward + rightHandOffset);
            // rightHandEquipment.transform.rotation = cameraPos.rotation;
            // rightHandEquipment.transform.position = cameraPos.position + cameraPos.forward + rightHandOffset;
        }
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
        switch(so.slot){
            case EquipmentSO.EquipmentSlots.HEAD: return EquipHead(pickup, so);
            case EquipmentSO.EquipmentSlots.FEET: return EquipFeet(pickup, so);
            case EquipmentSO.EquipmentSlots.TORSO: return EquipTorso(pickup, so);
            case EquipmentSO.EquipmentSlots.LEFTHAND: return EquipLeftHand(pickup, so);
            case EquipmentSO.EquipmentSlots.RIGHTHAND: return EquipRightHand(pickup, so);
        }
        return false;
    }

    void EnablePhysics(GameObject obj){
        Rigidbody rig = obj.GetComponent<Rigidbody>();
        // rig.useGravity = true;
        rig.isKinematic = false;
    }
    void DisablePhysics(GameObject obj){
        Rigidbody rig = obj.GetComponent<Rigidbody>();
        // rig.useGravity = false;
        rig.isKinematic = true;
    }

    bool EquipHead(GameObject pickup, EquipmentSO so){
        if (headEquipment) DropEquipment(EquipmentSO.EquipmentSlots.HEAD);
        headEquipment = pickup;
        headOffset = so.posOffset;
        DisablePhysics(headEquipment);
        headEquipment.transform.parent = cameraPos.parent;
        headEquipment.transform.position = cameraPos.position + so.posOffset;

        return true;
    }
    bool EquipFeet(GameObject pickup, EquipmentSO so){
        if (feetEquipment) DropEquipment(EquipmentSO.EquipmentSlots.FEET);
        feetEquipment = pickup;
        DisablePhysics(feetEquipment);
        feetEquipment.transform.parent = cameraPos.parent;
        feetEquipment.transform.position = cameraPos.position + (-cameraPos.up) + so.posOffset;
        return true;
    }
    bool EquipTorso(GameObject pickup, EquipmentSO so){
        if (torsoEquipment) DropEquipment(EquipmentSO.EquipmentSlots.TORSO);
        torsoEquipment = pickup;
        torsoEquipment.GetComponent<Collider>().enabled = false;
        DisablePhysics(torsoEquipment);
        torsoEquipment.transform.parent = cameraPos.parent;
        torsoEquipment.transform.position = cameraPos.position + so.posOffset;
        // torsoEquipment.transform.rotation = cameraPos.rotation;
        return true;
    }
    bool EquipLeftHand(GameObject pickup, EquipmentSO so){
        if (leftHandEquipment) DropEquipment(EquipmentSO.EquipmentSlots.LEFTHAND);
        leftHandEquipment = pickup;
        DisablePhysics(leftHandEquipment);
        leftHandEquipment.transform.parent = cameraPos.parent;
        leftHandEquipment.transform.position = cameraPos.position + cameraPos.forward + so.posOffset;
        return true;
    }
    bool EquipRightHand(GameObject pickup, EquipmentSO so){
        if (rightHandEquipment) DropEquipment(EquipmentSO.EquipmentSlots.RIGHTHAND);
        rightHandEquipment = pickup;
        rightHandOffset = so.posOffset;
        DisablePhysics(rightHandEquipment);
        rightHandEquipment.transform.parent = cameraPos.parent;
        // rightHandEquipment.transform.position = cameraPos.position + cameraPos.forward + rightHandOffset;
        rightHandEquipment.transform.rotation = cameraPos.parent.rotation;
        return true;
    }

    void DoMainAction(){
        if (rightHandEquipment){
            Rigidbody tempRig = rightHandEquipment.GetComponent<Rigidbody>();
            DropRightHand();
            tempRig.AddForce( cameraPos.forward * throwForce);
        }
    }
    void DoSecondAction(){
        if (leftHandEquipment){
            Rigidbody tempRig = leftHandEquipment.GetComponent<Rigidbody>();
            DropLeftHand();
            tempRig.AddForce( cameraPos.forward * throwForce);
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
            currentItem.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            
            currentItem.SetActive(true);
            // inventorySlots[currentlySelectedSlot].text = currentlySelectedSlot + ". Empty";
            inventorySlots[currentlySelectedSlot].sprite = null;
            inventorySlots[currentlySelectedSlot].color = new Color(0, 0, 0, 0);
            inventoryItems[currentlySelectedSlot] = null;
        }
    }

    void DropEquipment(EquipmentSO.EquipmentSlots area){
        switch (area){
            case EquipmentSO.EquipmentSlots.HEAD: DropHead();
            break;
            case EquipmentSO.EquipmentSlots.FEET: DropFeet();
            break;
            case EquipmentSO.EquipmentSlots.TORSO: DropTorso();
            break;
            case EquipmentSO.EquipmentSlots.LEFTHAND: DropLeftHand();
            break;
            case EquipmentSO.EquipmentSlots.RIGHTHAND: DropRightHand();
            break;
        }
    }

    void DropHead(){
        if(headEquipment) {
            EnablePhysics(headEquipment);
            headEquipment.transform.parent = null;
            headEquipment.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            headEquipment = null;
        }
    }

    void DropFeet(){
        if(feetEquipment) {
            EnablePhysics(feetEquipment);
            feetEquipment.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            feetEquipment = null;
        }
    }

    void DropTorso(){
        if(torsoEquipment) {
            EnablePhysics(torsoEquipment);
            torsoEquipment.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            torsoEquipment = null;
        }
    }

    void DropLeftHand(){
        if(leftHandEquipment) {
            EnablePhysics(leftHandEquipment);
            leftHandEquipment.transform.parent = null;
            leftHandEquipment.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            leftHandEquipment = null;
        }
    }

    void DropRightHand(){
        if(rightHandEquipment) {
            EnablePhysics(rightHandEquipment);
            rightHandEquipment.transform.parent = null;
            rightHandEquipment.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            rightHandEquipment = null;
        }
    }
}
