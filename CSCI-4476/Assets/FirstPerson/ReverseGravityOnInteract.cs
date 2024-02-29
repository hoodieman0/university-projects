using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ReverseGravityOnInteract : MonoBehaviour, IInteractable
{
    Rigidbody rig;
    float force = 9.81f;
    [SerializeField] float multiplier = 100f;
    bool state = false;

    void Awake(){
        rig = GetComponent<Rigidbody>();
    }

    void Update(){
        if (state){
            rig.AddForce(Vector3.up * force * multiplier * Time.fixedDeltaTime, ForceMode.Force);
        }
    }

    public void StartInteract(Interactor interactor){
        state = true;
    }
    public void WhileInteract(Interactor interactor){

    }
    public void StopInteract(Interactor interactor){
        state = false;
    }
}
