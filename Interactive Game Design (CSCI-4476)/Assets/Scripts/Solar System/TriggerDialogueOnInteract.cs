using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TriggerDialogueOnInteract : MonoBehaviour, IInteractable
{
    [SerializeField] List<Dialogue> dialogues;

    public void StartInteract(Interactor _){
        DialogueSystem.instance.Interrupt(dialogues);
    }
    public void StopInteract(Interactor _){

    }
}
