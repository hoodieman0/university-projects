using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class InventoryManager : MonoBehaviour
{
    public static InventoryManager          instance;
    [SerializeField]    Transform           cameraPos;
    [SerializeField]    TextMeshProUGUI     currencyText;
    [SerializeField]    TextMeshProUGUI[]   inventorySlots;
    [SerializeField]    float               dropDistance            =   2f;
                        GameObject[]        inventoryItems;
                        GameObject          headEquipment;  // could make this an array of gameObjects, then dedicate position to head, etc.
                        GameObject          feetEquipment;
                        GameObject          torsoEquipment;
                        GameObject          leftHandEquipment;
                        GameObject          rightHandEquipment;
                        uint                maxInventorySlots       =   3;
                        int                 currentlySelectedSlot   =   0;
                        int                 currencyCount           =   0;

    void OnValidate(){
        if (inventorySlots.Length > maxInventorySlots){
            Debug.LogError("Too many slots serialized!", gameObject);
        }
    }

    void OnEnable(){
        InputManager.inventoryAction += SelectInventorySlot;
        InputManager.dropAction += DropItem;
    }

    void OnDisable(){
        InputManager.inventoryAction -= SelectInventorySlot;
        InputManager.dropAction -= DropItem;
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
            headEquipment.transform.position = cameraPos.position + cameraPos.up;
            headEquipment.transform.rotation = cameraPos.rotation;
        }
        if (feetEquipment) {
            feetEquipment.transform.position = cameraPos.position + cameraPos.up;
            feetEquipment.transform.rotation = cameraPos.rotation;
        }
        if (torsoEquipment) {
            torsoEquipment.transform.position = cameraPos.position + cameraPos.up;
            torsoEquipment.transform.rotation = cameraPos.rotation;
        }
        if (leftHandEquipment) {
            leftHandEquipment.transform.position = cameraPos.position + cameraPos.up;
            leftHandEquipment.transform.rotation = cameraPos.rotation;
        }
        if (rightHandEquipment) {
            rightHandEquipment.transform.position = cameraPos.position + cameraPos.up;
            rightHandEquipment.transform.rotation = cameraPos.rotation;
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
        inventorySlots[slot].text = (slot + 1) + ". " + pickup.name;
        inventoryItems[slot] = pickup;
    }

    bool PickupEquipment(GameObject pickup, EquipmentSO so){
        switch(so.slot){
            case EquipmentSO.EquipmentSlots.HEAD: return EquipHead(pickup);
            case EquipmentSO.EquipmentSlots.FEET: return EquipFeet(pickup);
            case EquipmentSO.EquipmentSlots.TORSO: return EquipTorso(pickup);
            case EquipmentSO.EquipmentSlots.LEFTHAND: return EquipLeftHand(pickup);
            case EquipmentSO.EquipmentSlots.RIGHTHAND: return EquipRightHand(pickup);
        }
        return false;
    }

    bool EquipHead(GameObject pickup){
        if (headEquipment) DropEquipment(EquipmentSO.EquipmentSlots.HEAD);
        headEquipment = pickup;
        return true;
    }
    bool EquipFeet(GameObject pickup){
        if (feetEquipment) DropEquipment(EquipmentSO.EquipmentSlots.FEET);
        feetEquipment = pickup;
        return true;
    }
    bool EquipTorso(GameObject pickup){
        if (torsoEquipment) DropEquipment(EquipmentSO.EquipmentSlots.TORSO);
        torsoEquipment = pickup;
        return true;
    }
    bool EquipLeftHand(GameObject pickup){
        if (leftHandEquipment) DropEquipment(EquipmentSO.EquipmentSlots.LEFTHAND);
        leftHandEquipment = pickup;
        return true;
    }
    bool EquipRightHand(GameObject pickup){
        if (rightHandEquipment) DropEquipment(EquipmentSO.EquipmentSlots.RIGHTHAND);
        rightHandEquipment = pickup;
        return true;
    }

    void SelectInventorySlot(int index){
        inventorySlots[currentlySelectedSlot].color = Color.white;
        currentlySelectedSlot = index;
        inventorySlots[currentlySelectedSlot].color = Color.green;
    }

    void DropItem(){
        if(inventoryItems[currentlySelectedSlot] != null){
            GameObject currentItem = inventoryItems[currentlySelectedSlot];
            currentItem.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            
            currentItem.SetActive(true);
            inventorySlots[currentlySelectedSlot].text = currentlySelectedSlot + ". Empty";
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
            headEquipment.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            headEquipment = null;
        }
    }

    void DropFeet(){
        if(feetEquipment) {
            feetEquipment.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            feetEquipment = null;
        }
    }

    void DropTorso(){
        if(torsoEquipment) {
            torsoEquipment.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            torsoEquipment = null;
        }
    }

    void DropLeftHand(){
        if(leftHandEquipment) {
            leftHandEquipment.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            leftHandEquipment = null;
        }
    }

    void DropRightHand(){
        if(rightHandEquipment) {
            rightHandEquipment.transform.position = cameraPos.position + (cameraPos.forward * dropDistance);
            rightHandEquipment = null;
        }
    }
}
