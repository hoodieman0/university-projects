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
        ren.material.color = Color.HSVToRGB(value/100, 1, 1);
    }

    public void StartInteract(Interactor _){ }
    public void StopInteract(Interactor _){ }
}
