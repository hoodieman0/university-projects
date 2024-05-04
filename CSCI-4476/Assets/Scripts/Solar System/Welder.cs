using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Welder : MonoBehaviour, IActionable
{
    public float weldSpeed = 20f;
    public float weldDistance = 30f;
    bool isWelding = false;
    public void StartAction(){
        isWelding = true;
    }
    void FixedUpdate(){
        if (!isWelding) return;
        if (Physics.Raycast(Camera.main.transform.position, Camera.main.transform.forward, out RaycastHit hit, weldDistance))
        {
            // If the object has the interface
            if (hit.transform.gameObject.GetComponent<Weldable>() != null) {
                isWelding = true;
                hit.transform.gameObject.GetComponent<Weldable>().ProgressWeld(weldSpeed * Time.deltaTime);
            }
            // If the object does not have the interface
            else {
                isWelding = false;
            }
        }
        // If no hit
        else isWelding = false;
    }
    public void StopAction(){
        isWelding = false;
    }
}
