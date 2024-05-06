using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Fuelable : MonoBehaviour, IInteractable
{
    public Transform nozzleFillPosition;
    public float fuelLimit = 1000f;
    public float currentFuel = 250f;
    bool isOccupied = false;
    public bool isFull = false;

    void Awake(){
        isFull = currentFuel > fuelLimit ? true : false;
    }

    public void AddFuel(float amount){
        if (isFull) return;
        currentFuel += amount;
        if (currentFuel > fuelLimit){
            currentFuel = fuelLimit;
            isFull = true;
            NotifyFullTank();
        }
    }

    void NotifyFullTank(){
        // play animation
        // play sound
        Debug.Log("The tank is full!");
    }

    public void StartInteract(Interactor interactor){
        int slot = (int)EquipmentSO.EquipmentSlots.RIGHTHAND;
        GameObject nozzle = InventoryManager.instance.equipmentGameObj[slot];
        // there is nothing in the slot and the player is holding a nozzle
        if (!isOccupied && nozzle.GetComponent<FuelNozzle>() != null){
            // cache object

            // set nozzle's parent to hole slot and move it
            nozzle.transform.position = nozzleFillPosition.position;
            nozzle.transform.parent = nozzleFillPosition;

            // reset its rotation
            nozzle.transform.rotation = nozzleFillPosition.rotation;

            // remove nozzle from inventory item
            InventoryManager.instance.equipmentGameObj[slot] = null;
            nozzle.GetComponent<Collider>().enabled = true;

            // make it so it can't move
            nozzle.GetComponent<Rigidbody>().isKinematic = true;
            isOccupied = true;
        }
    }

    void FixedUpdate(){
        isOccupied = nozzleFillPosition.transform.childCount > 0 ? true : false;
        if (isOccupied){
            float fuelRate = nozzleFillPosition.GetChild(0).GetComponent<FuelNozzle>().flowRate;
            AddFuel(fuelRate * Time.deltaTime);
        }
        else isOccupied = false;
    }
    public void StopInteract(Interactor interactor){
        
    }
}
