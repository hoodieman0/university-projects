using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody))]
public class Grabbable : MonoBehaviour, IInteractable
{
    FixedJoint joint;
    [SerializeField] float breakForce = 100f;
    public void StartInteract(Interactor interactor){
        joint = gameObject.AddComponent<FixedJoint>();
        joint.connectedBody = interactor.GetComponent<Rigidbody>();
        joint.breakForce = breakForce;
        joint.breakTorque= breakForce;
    }

    public void StopInteract(Interactor interactor){
        Destroy(joint);
    }
}
