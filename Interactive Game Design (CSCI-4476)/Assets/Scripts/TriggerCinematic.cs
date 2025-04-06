using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class TriggerCinematic : MonoBehaviour
{
    [SerializeField]    Transform       target;
    [SerializeField]    Transform[]     dollyLocations;
    [SerializeField]    bool            triggerOnce         = true;
                        bool            hasBeenTriggered    = false;
    void OnTriggerEnter(Collider other){
        if (other.gameObject.CompareTag("Player") && !hasBeenTriggered){
            StartCoroutine(CinematicCamera.instance.TriggerCinematic(target, dollyLocations));
            if (triggerOnce) hasBeenTriggered = true;
        }
    }
}
