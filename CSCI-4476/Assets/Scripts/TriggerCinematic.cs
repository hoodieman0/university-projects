using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class TriggerCinematic : MonoBehaviour
{
    [SerializeField]    Transform       target;
    [SerializeField]    Transform[]     dollyLocations;
    void OnTriggerEnter(Collider other){
        if (other.gameObject.CompareTag("Player")){
            StartCoroutine(CinematicCamera.instance.TriggerCinematic(target, dollyLocations));
        }
    }
}
