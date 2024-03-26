using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KickOnInteract : MonoBehaviour, IInteractable
{
    [SerializeField] float kickMultiplier = 2f;
    float kickForce = 500f;
    Rigidbody rig;

    void Awake(){
        rig = GetComponent<Rigidbody>();
    }

    public void StartInteract(Interactor interactor){
        rig.AddForce(Vector3.up * kickForce * kickMultiplier, ForceMode.Force);
    }
    public void WhileInteract(Interactor interactor){

    }
    public void StopInteract(Interactor interactor){

    }
}
