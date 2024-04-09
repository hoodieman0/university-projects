using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class TriggerCinematic : MonoBehaviour
{
    [SerializeField]    Transform           target;
    [SerializeField]    Queue<Transform>    dollyLocations;
    void OnTriggerEnter(Collider other){
        if (other.gameObject.CompareTag("Player")){
            
        }
    }
}
