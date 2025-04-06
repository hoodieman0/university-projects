using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChangeColorOnInteract : MonoBehaviour, IInteractable
{
    [SerializeField] Color startColor;
    [SerializeField] Color lookColor;
    [SerializeField] Color whileInteractingColor;

    Renderer ren;
    void Awake(){
        ren = GetComponent<Renderer>();
        ChangeToStartingColor();
    }

    void ChangeToStartingColor(){
        ren.material.color = startColor;
    }

    public void StartInteract(Interactor interactor){
        ren.material.color = lookColor;
    }
    public void WhileInteract(Interactor interactor){
        if (ren.material.color != whileInteractingColor) {
            ren.material.color = whileInteractingColor;
        }
    }
    public void StopInteract(Interactor interactor){
        ChangeToStartingColor();
    }
}
