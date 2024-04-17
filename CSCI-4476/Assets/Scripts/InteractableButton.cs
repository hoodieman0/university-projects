using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class InteractableButton : MonoBehaviour, IInteractable
{
    [SerializeField] ButtonManager manager;
    public void StartInteract(Interactor _){
        StartCoroutine(manager.OnButtonPressed);
    }

    public void StopInteract(Interactor _){

    }
}
