using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PressurePlate : MonoBehaviour
{
    [SerializeField] Transform button;
    [SerializeField] float yMin = 0.1f;
    float yMax; // set in editor by object
    [SerializeField] bool pressed = false;
    [SerializeField] GameObject target;

    void Start(){
        yMax = button.localPosition.y;
    }

    void Update(){
        if (button.localPosition.y < yMin){
            button.localPosition = new(0f, yMin, 0f);
        }
        else if (button.localPosition.y > yMax){
            button.localPosition = new(0f, yMax, 0f);
        }
        else if (button.localPosition.y == yMin && !pressed){
            pressed = true;
            target.GetComponent<IInteractable>()?.StartInteract();
        }
        else if (pressed && button.localPosition.y != yMin){
            target.GetComponent<IInteractable>()?.StopInteract();
            pressed = false;
        }
    }
}
