using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UniverseSimulation : MonoBehaviour
{
    [SerializeField] CelestialBody[] bodies;
    static UniverseSimulation instance;


    void Awake(){
        Time.fixedDeltaTime = Universe.physicsTimeStep;
    }

    void FixedUpdate(){
        foreach (CelestialBody body in bodies){
            body.UpdateVelocity(bodies, Universe.physicsTimeStep);
        }
        foreach (CelestialBody body in bodies){
            body.UpdatePosition(Universe.physicsTimeStep);
        }
    }

    public static CelestialBody[] Bodies {
        get {
            return Instance.bodies;
        }
    }

    static UniverseSimulation Instance {
        get {
            if (instance == null) {
                instance = FindObjectOfType<UniverseSimulation> ();
            }
            return instance;
        }
    }
}
