using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Collider))]
[RequireComponent(typeof(Rigidbody))]
public class Pickupable : MonoBehaviour, IInteractable
{
    [SerializeField] PickupSO pickup;
    public void StartInteract(Interactor interactor){
        InventoryManager.instance.Pickup(pickup);
        gameObject.SetActive(false);
    }

    public void StopInteract(Interactor interactor){}
}
