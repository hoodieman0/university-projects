using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HoleInteraction : MonoBehaviour, IInteractable
{
    public Transform    holePosition;
    public bool         isCovered = false;

    public void StartInteract(Interactor interactor){
        if (!isCovered && InventoryManager.instance.inventoryItem != null){
            // this is not the item needed
            if (InventoryManager.instance.inventoryItem?.GetComponent<Pickupable>().getSO().objName != "Hull Plate") return; 

            // cache object
            GameObject plate = InventoryManager.instance.inventoryItem;

            // set plate's parent to hole slot and move it
            plate.transform.position = holePosition.position;
            plate.transform.rotation = holePosition.rotation;
            plate.transform.parent = holePosition;

            // reenable plate and remove it from inventory item
            plate.SetActive(true);
            InventoryManager.instance.inventoryItem = null;
            plate.GetComponent<Collider>().enabled = true;

            // make it so it can't move
            plate.GetComponent<Rigidbody>().isKinematic = true;
            
            // make it so it cannot be picked up again
            Destroy(plate.GetComponent<Pickupable>());
        }
    }
    public void StopInteract(Interactor interactor){
        
    }
}
