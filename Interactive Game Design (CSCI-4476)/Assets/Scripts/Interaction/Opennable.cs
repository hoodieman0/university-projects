using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Collider))]
[RequireComponent(typeof(Rigidbody))]
public class Opennable : MonoBehaviour, IInteractable
{
    [SerializeField] bool pushToOpen = true;
    [SerializeField] float maxRotation = 90f;
    [SerializeField] float moveDuration = 1f;
    float startingRotation;

    void Start(){
        startingRotation = transform.parent.rotation.y;
        maxRotation = pushToOpen ? -maxRotation : maxRotation;
    }

    public void StartInteract(Interactor interactor){
        if (!LeanTween.isTweening(transform.parent.gameObject)){
            float target = transform.parent.rotation.y == startingRotation ? maxRotation : startingRotation;
            LeanTween.rotateY(transform.parent.gameObject, target, moveDuration);
        }
    }

    public void StopInteract(Interactor interactor){
        
    }
}
