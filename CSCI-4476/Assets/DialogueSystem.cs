using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.VisualScripting;
using UnityEngine;

public class DialogueSystem : MonoBehaviour
{
    public static DialogueSystem            instance;
    [SerializeField]    List<Dialogue>      dialogueQueue;
    [SerializeField]    TextMeshProUGUI     speakerField;
    [SerializeField]    TextMeshProUGUI     subtitleField;  // will need coroutines
    Dialogue                                currentDialogue;
    AudioSource                             aS;

    void Awake(){
        if (instance == null) {
            instance = this;
            aS = GetComponent<AudioSource>();
        }
        else {
            Destroy(gameObject);
        }
    }

    void FixedUpdate(){ // could be coroutines
        if (dialogueQueue.Count > 0 && !aS.isPlaying){
            PlayAudio();
        }
    }

    void PlayAudio(){
        currentDialogue = dialogueQueue[0];
        aS.PlayOneShot(currentDialogue.audioClip);
        dialogueQueue.Remove(currentDialogue);      // pop front current dialogue
    }

    public void Interrupt(List<Dialogue> dialogues){
        aS.Stop();
        // clear subtitles
        dialogueQueue.Insert(0, currentDialogue);   // bug where return plays before interrupt
        QueuePushFront(dialogues);        
        PlayAudio();                                // Get ahead of race condition
    }

    public void QueuePushFront(List<Dialogue> dialogues){
        dialogueQueue.InsertRange(0, dialogues);
    }

    public void QueuePushBack(List<Dialogue> dialogues){
        dialogueQueue.AddRange(dialogues);
    }
}
