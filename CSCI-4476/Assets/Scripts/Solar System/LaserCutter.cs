using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LaserCutter : MonoBehaviour, IActionable
{
    public Transform    cam;
    public  Color       laserColor  =   Color.red;
    public  GameObject  laserGO;
            bool        isFiring    =   false;
    public  bool        isHitting   =   false;
    public  float       cutDamage   =   25f;
    public  float       cutDistance =   25f;

    public void Awake(){
        laserGO.SetActive(false);
        laserGO.GetComponent<Renderer>().material.color = laserColor;
    }

    public void StartAction(){
        laserGO.SetActive(true);
        isFiring = true;
    }

    void FixedUpdate(){
        if (!isFiring) return;
        if (Physics.Raycast(cam.position, cam.forward, out RaycastHit hit, cutDistance))
        {
            // If the object has the interface
            if (hit.transform.gameObject.GetComponent<Cuttable>() != null) {
                isHitting = true;
                hit.transform.gameObject.GetComponent<Cuttable>().DealDamage(cutDamage * Time.deltaTime);
            }
            // If the object does not have the interface
            else {
                isHitting = false;
            }
        }
        // If no hit
        else isHitting = false;
    }

    public void StopAction(){
        laserGO.SetActive(false);
        isFiring = false;
    }
}
