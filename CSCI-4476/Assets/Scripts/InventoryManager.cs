using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class InventoryManager : MonoBehaviour
{
    public static InventoryManager instance;
    [SerializeField]    TextMeshProUGUI     currencyText;
    [SerializeField]    TextMeshProUGUI[]   inventorySlots;
                        GameObject[]            inventoryItems;
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
        InputManager.dropAction += Drop;
    }

    void Awake(){
        if (!instance) {
            instance = this;
            inventoryItems = new GameObject[3];
            SelectInventorySlot(0);
        } 
        else Destroy(gameObject);
    }

    public void Pickup(GameObject obj){
        PickupSO pickup = obj.GetComponent<Pickupable>().getSO();
        
        switch (pickup){
            case CurrencySO:
                // add to counter
                PickupCurrency((CurrencySO) pickup);
                break;
            case ItemSO:
                // add to inventory
                PickupItem(obj);
                break;
            case EquipmentSO:
                // add to player
                PickupEquipment(obj);
                break;
            default:
                break;
        }
    }

    void PickupCurrency(CurrencySO pickup){
        currencyCount += (int) pickup.value;
        currencyText.text = currencyCount.ToString();
    }
    
    void PickupItem(GameObject pickup){
        inventorySlots[currentlySelectedSlot].text = (currentlySelectedSlot + 1) + ". " + pickup.name;
        inventoryItems[currentlySelectedSlot] = pickup;
    }

    void PickupEquipment(GameObject pickup){

    }

    void SelectInventorySlot(int index){
        inventorySlots[currentlySelectedSlot].color = Color.white;
        currentlySelectedSlot = index;
        inventorySlots[currentlySelectedSlot].color = Color.green;
    }

    void Drop(){
        if(inventorySlots[currentlySelectedSlot] != null){
            GameObject currentItem = inventoryItems[currentlySelectedSlot];
            currentItem.transform.position = transform.position;
            
            currentItem.SetActive(true);
            inventorySlots[currentlySelectedSlot].text = currentlySelectedSlot + ". Empty";
            inventoryItems[currentlySelectedSlot] = null;

        }
    }


}
