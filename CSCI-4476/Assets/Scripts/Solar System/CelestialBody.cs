using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[ExecuteInEditMode]
[RequireComponent(typeof(Rigidbody))]
public class CelestialBody : MonoBehaviour
{
    public   float       mass {get; private set;}
    public   float       radius;
    public   float       surfaceGravity;
    public   Vector3     initialVelocity;
    public   String      bodyName;
            Vector3     currentVelocity;
            Rigidbody   rig;
            Transform   model;
    void OnValidate(){
        mass = surfaceGravity * radius * radius / Universe.gravitationalConstant;
        model = transform.GetChild (0);
        model.localScale = Vector3.one * radius;
        gameObject.name = bodyName;
    }
    void Awake() {
        rig = GetComponent<Rigidbody>();
        rig.mass = mass;
        currentVelocity = initialVelocity;
    }

    public void UpdateVelocity(CelestialBody[] allBodies, float timeStep){
        foreach (CelestialBody otherBody in allBodies){
            if (otherBody != this){
                Rigidbody otherRig = otherBody.GetComponent<Rigidbody>();
                float distSqr = (otherRig.position - rig.position).sqrMagnitude;
                Vector3 forceDir = (otherRig.position - rig.position).normalized;

                // F = G (m1 * m2) / r^2
                Vector3 force = forceDir * Universe.gravitationalConstant * mass * otherBody.mass / distSqr; 
                Vector3 acceleration = force / mass;
                currentVelocity += acceleration * timeStep;
            }
        }
    }

    public void UpdatePosition(float timeStep){
        rig.position += currentVelocity * timeStep;
    }
}
