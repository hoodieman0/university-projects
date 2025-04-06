using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TriggerSunCollision : MonoBehaviour
{
    void OnTriggerEnter(Collider other){
        if (other.gameObject.CompareTag("Player")) Application.Quit();
        other.gameObject.SetActive(false);
    }
}
