using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Collider))]
[RequireComponent(typeof(Rigidbody))]
public class Pickupable : MonoBehaviour, IInteractable
{
    [SerializeField] PickupSO pickup;

    public PickupSO getSO() {return pickup; }

    public void StartInteract(Interactor interactor){
        if (InventoryManager.instance.Pickup(gameObject))
            gameObject.SetActive(false);
    }

    public void StopInteract(Interactor interactor){}
}
