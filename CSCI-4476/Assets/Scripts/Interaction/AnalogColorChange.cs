using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnalogColorChange : MonoBehaviour, IInteractable
{
    [SerializeField] Color[] colorArr;
    Renderer ren;
    void Start(){
        ren = gameObject.GetComponent<Renderer>();
        ren.material.color = colorArr[0];
    }

    public void SendAnalogValue(float value){
        if (value >= 0f && value < 25f) {
            ren.material.color = colorArr[0];
        }
        else if (value >= 25f && value < 50f){
            ren.material.color = colorArr[1];
        }
        else if (value >= 50f && value < 75f){
            ren.material.color = colorArr[2];
        }
        else {
            ren.material.color = colorArr[3];
        }
    }

    public void StartInteract(Interactor _){ }
    public void StopInteract(Interactor _){ }
}
