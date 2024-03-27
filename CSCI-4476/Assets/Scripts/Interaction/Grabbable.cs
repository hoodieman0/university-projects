using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Grabbable : MonoBehaviour, IInteractable
{
    FixedJoint joint;
    [SerializeField] float breakForce = 100f;
    public void StartInteract(Interactor interactor){
        Debug.Log("Grab");
        joint = gameObject.AddComponent<FixedJoint>();
        joint.connectedBody = interactor.GetComponent<Rigidbody>();
        joint.breakForce = breakForce;
        joint.breakTorque= breakForce;
    }

    public void StopInteract(Interactor interactor){
        Debug.Log("Drop");
        Destroy(joint);
    }
}
