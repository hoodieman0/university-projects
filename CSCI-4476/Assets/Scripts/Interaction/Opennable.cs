using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody))]
public class Opennable : MonoBehaviour, IInteractable
{
    [SerializeField] bool pushToOpen = true;
    [SerializeField] float maxRotation = 90f;

    public void StartInteract(Interactor interactor){
        
    }

    public void StopInteract(Interactor interactor){
        
    }
}
