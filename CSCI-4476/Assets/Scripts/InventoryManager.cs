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

    public bool Pickup(GameObject obj){
        PickupSO pickup = obj.GetComponent<Pickupable>().getSO();
        
        switch (pickup){
            case CurrencySO:
                // add to counter
                return PickupCurrency((CurrencySO) pickup);
            case ItemSO:
                // add to inventory
                return PickupItem(obj);
            case EquipmentSO:
                // add to player
                return PickupEquipment(obj);
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
        return false;
    }

    void AddItemToSlot(GameObject pickup, int slot){
        inventorySlots[slot].text = (slot + 1) + ". " + pickup.name;
        inventoryItems[slot] = pickup;
    }

    bool PickupEquipment(GameObject pickup){
        return false;
    }

    void SelectInventorySlot(int index){
        inventorySlots[currentlySelectedSlot].color = Color.white;
        currentlySelectedSlot = index;
        inventorySlots[currentlySelectedSlot].color = Color.green;
    }

    void Drop(){
        if(inventoryItems[currentlySelectedSlot] != null){
            GameObject currentItem = inventoryItems[currentlySelectedSlot];
            currentItem.transform.position = transform.position;
            
            currentItem.SetActive(true);
            inventorySlots[currentlySelectedSlot].text = currentlySelectedSlot + ". Empty";
            inventoryItems[currentlySelectedSlot] = null;

        }
    }


}
