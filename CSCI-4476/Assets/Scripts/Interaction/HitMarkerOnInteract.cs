using System.Collections;
using System.Collections.Generic;
using Microsoft.Unity.VisualStudio.Editor;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class HitMarkerOnInteract : MonoBehaviour, IInteractable
{
    [SerializeField] TMP_Text crosshair;


    public void StartInteract(Interactor interactor){
        crosshair.text = "X"; 
    }
    public void WhileInteract(Interactor interactor){

    }
    public void StopInteract(Interactor interactor){
        crosshair.text = "";
    }
}
