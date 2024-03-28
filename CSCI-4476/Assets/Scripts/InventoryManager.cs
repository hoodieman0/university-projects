using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class InventoryManager : MonoBehaviour
{
    public static InventoryManager instance;
    [SerializeField] TextMeshProUGUI currencyText;
    int currencyCount = 0;

    void Awake(){
        if (!instance) instance = this; 
        else Destroy(gameObject);
    }

    public void Pickup(PickupSO type){
        switch (type){
            case CurrencySO:
                // add to counter
                PickupCurrency();
                break;
            case ItemSO:
                // add to inventory
                break;
            case EquipmentSO:
                // add to player
                break;
            default:
                break;
        }
    }

    void PickupCurrency(){
        currencyCount++;
        currencyText.text = currencyCount.ToString();
    }
    
    void PickupItem(){

    }

    void PickupEquipment(){

    }


}
