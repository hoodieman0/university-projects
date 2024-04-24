using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AddDialogueOnTrigger : MonoBehaviour
{
    [SerializeField] List<Dialogue> dialogues;

    void OnTriggerEnter(Collider other){
        if (other.CompareTag("player")){
            DialogueSystem.instance.Interrupt(dialogues);
        }
    }
}
