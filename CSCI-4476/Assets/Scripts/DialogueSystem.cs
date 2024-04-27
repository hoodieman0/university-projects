using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.VisualScripting;
using UnityEngine;

public class DialogueSystem : MonoBehaviour
{
    public static DialogueSystem            instance;
    [SerializeField]    List<Dialogue>      dialogueQueue;
    [SerializeField]    GameObject          subtitleHolder;
    [SerializeField]    TextMeshProUGUI     speakerField;
    [SerializeField]    TextMeshProUGUI     subtitleField;  // will need coroutines
    Dialogue                                currentDialogue;
    AudioSource                             aS;
                        string              subtitleText;
                        bool                playingSubtitles    =   false;

    void Awake(){
        if (instance == null) {
            instance = this;
        }
        else {
            Destroy(gameObject);
        }
    }

    void Start(){
        aS = AudioManager.instance.aS;
    }

    void FixedUpdate(){ // could be coroutines
        if (dialogueQueue.Count > 0 && !aS.isPlaying && !playingSubtitles){
           StartCoroutine(PlayAudio());
        }
    }

    IEnumerator PlayAudio(){
        playingSubtitles = true;
        currentDialogue = dialogueQueue[0];
        dialogueQueue.Remove(currentDialogue);      // pop front current dialogue
        
        yield return new WaitForSeconds(currentDialogue.delayBefore);
        subtitleHolder.SetActive(true);
        
        aS.PlayOneShot(currentDialogue.audioClip);

        yield return StartCoroutine(StaggerSubtitleText());

        yield return new WaitForSeconds(currentDialogue.delayAfter);
        subtitleHolder.SetActive(false);
        playingSubtitles = false;
    }

    IEnumerator StaggerSubtitleText(){
        speakerField.text = currentDialogue.speaker;
        subtitleField.text = "";
        subtitleText = currentDialogue.subtitle;

        float timeLength = currentDialogue.audioClip.length;
        float timePerChar = (timeLength * 0.75f) / subtitleText.Length;
        // float timePerChar = timeLength  / (subtitleText.Length * dialogueSpeed);


        foreach (char c in subtitleText){
            subtitleField.text += c;
            yield return new WaitForSeconds(timePerChar);
        }
        yield return new WaitForSeconds(timeLength * 0.25f);
        subtitleText = "";
    }

    public void Interrupt(List<Dialogue> dialogues){
        aS.Stop();
        StopAllCoroutines(); // clear subtitles
        subtitleField.text = "";
        subtitleText = "";
        dialogueQueue.Insert(0, currentDialogue);   // bug where return plays before interrupt
        QueuePushFront(dialogues);        
        StartCoroutine(PlayAudio());                                // Get ahead of race condition

    }

    public void QueuePushFront(List<Dialogue> dialogues){
        dialogueQueue.InsertRange(0, dialogues);
    }

    public void QueuePushBack(List<Dialogue> dialogues){
        dialogueQueue.AddRange(dialogues);
    }
}
