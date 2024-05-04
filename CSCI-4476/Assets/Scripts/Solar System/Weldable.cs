using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Renderer))]
[RequireComponent(typeof(Collider))]
public class Weldable : MonoBehaviour
{
    public Material     finalMaterial;
    public float weldProgress = 0f;
    public float totalProgress = 100f;

    public void ProgressWeld(float weldSpeed){
        weldProgress += weldSpeed;
        if (weldProgress > totalProgress){
            WeldObjects();
        }
    }

    void WeldObjects(){
        // play animation
        // play sound
        gameObject.SetActive(true);
        gameObject.GetComponent<Renderer>().material = finalMaterial;
    }
}
