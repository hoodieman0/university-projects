using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class InventoryManager : MonoBehaviour
{
    public static InventoryManager instance;
    [SerializeField] TextMeshProUGUI currencyText;
    [SerializeField] TextMeshProUGUI[] inventorySlots;
    ItemSO[] inventoryItems;
    uint maxInventorySlots = 3;
    int currentlySelectedSlot = 0;
    
    int currencyCount = 0;

    void OnValidate(){
        if (inventorySlots > maxInventorySlots){
            Debug.LogError("Too many slots", gameObject);
        }
    }

    void OnEnable(){
        InputManager.inventoryAction += SelectInventorySlot;
        InputManager.dropAction += Drop;
    }

    void Awake(){
        if (!instance) instance = this; 
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
                PickupItem((ItemSO) pickup);
                break;
            case EquipmentSO:
                // add to player
                PickupEquipment((EquipmentSO) pickup);
                break;
            default:
                break;
        }
    }

    void PickupCurrency(CurrencySO pickup){
        currencyCount += (int) pickup.value;
        currencyText.text = currencyCount.ToString();
    }
    
    void PickupItem(PickupSO pickup){
        inventorySlots[currentlySelectedSlot].text = pickup.name;
        inventoryItems[currentlySelectedSlot] = pickup;
    }

    void PickupEquipment(PickupSO pickup){

    }

    void SelectInventorySlot(int index){
        inventorySlots[currentlySelectedSlot].color = Color.white;
        currentlySelectedSlot = index;
        inventorySlots[currentlySelectedSlot].color = Color.green;
    }

    void Drop(GameObject obj){
        if(inventorySlots[currentlySelectedSlot] != null){
            GameObject currentItem = inventoryItems[currentlySelectedSlot];
            currentObj.transform.position = transform.position;
            
            inventorySlots[currentlySelectedSlot].text = currentlySelectedSlot + ". Empty";
            inventoryItems[currentlySelectedSlot] = null;

        }
    }


}
