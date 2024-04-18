using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class ButtonManager : MonoBehaviour
{
    [SerializeField] bool isToggle = false;
    [SerializeField] GameObject button;
    [SerializeField] bool startingState;
    [SerializeField] GameObject target;
    [SerializeField] float resetDuration;
    bool isPressed;
    bool willReset;
    float originalY = 1f;
    float minY = 0.51f;
    float moveDuration = 0.5f;

    void OnValidate(){
        if (target.GetComponent<IInteractable>() == null){
            target = null;
            Debug.LogError("Not a valid target for interaction!", gameObject);
        }
    }

    public IEnumerator OnButtonPressed(){
        isPressed = !isPressed;
        if (isPressed || !isToggle){
            target.GetComponent<IInteractable>().StartInteract();
            button.GetComponent<Renderer>().material.color = Color.green;
        }
        else{
            target.GetComponent<IInteractable>().StopInteract();
            button.GetComponent<Renderer>().material.color = Color.red;
        }
        LeanTween.moveLocalY(button, minY, moveDuration);
        yield return new WaitForSeconds(moveDuration);
        LeanTween.moveLocalY(button, originalY, moveDuration);
        if (willReset){
            StartCoroutine(Reset());
        }
    }

    IEnumerator Reset(){
        yield return new WaitForSeconds(resetDuration);
        isPressed = false;
    }
}
