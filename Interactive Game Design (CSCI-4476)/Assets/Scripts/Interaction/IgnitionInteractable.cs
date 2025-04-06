using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class IgnitionInteractable : MonoBehaviour, IInteractable
{
    [SerializeField] IgnitionStarterManager manager;
    public void StartInteract(Interactor _){
        manager.OnTurn();
    }

    public void StopInteract(Interactor _){
        manager.Reset();
    }
}
