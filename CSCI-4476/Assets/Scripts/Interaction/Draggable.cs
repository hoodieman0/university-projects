using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody))]
public class Draggable : MonoBehaviour, IInteractable
{
    [SerializeField] float breakForce = 100f;
    [SerializeField] float spring = 10f;
    [SerializeField] float damper = 1f;
    [SerializeField] float tolerance = 1f;
    [SerializeField] Vector2 distanceRange = Vector2.zero;
    SpringJoint joint;
    public void StartInteract(Interactor interactor){
        joint = gameObject.AddComponent<SpringJoint>();
        joint.connectedBody = interactor.GetComponent<Rigidbody>();
        joint.breakForce = breakForce;
        joint.breakTorque= breakForce;
        joint.spring= spring;
        joint.damper= damper;
        joint.tolerance= tolerance;
        joint.minDistance= distanceRange.x;
        joint.maxDistance= distanceRange.y;
    }

    public void StopInteract(Interactor interactor){
        Destroy(joint);
    }
}
