using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class IgnitionStarterManager : MonoBehaviour
{
    [SerializeField] GameObject turnKey;
    [SerializeField] GameObject target;
    [SerializeField] float timePerInteract = 1f;
    [SerializeField] float resetDuration = 1f;
    bool isPressed;
    float originalYRot = 0f;
    float maxYRot = 90f;
    float moveDuration = 0.2f;
    float timer = 0f;

    void OnValidate(){
        if (target == null) return;
        if (target?.GetComponent<IInteractable>() == null){
            target = null;
            Debug.LogError("Not a valid target for interaction!", gameObject);
        }
    }
    public void OnTurn(){
        if (LeanTween.isTweening(turnKey)){
            LeanTween.cancel(turnKey);
        }
        // LeanTween.rotateY(turnKey, maxYRot, moveDuration);
        LeanTween.rotateLocal(turnKey, new(0f, maxYRot, 0f), moveDuration);
        isPressed = true;
    }

    void Update(){
        timer += Time.deltaTime;
        if (isPressed && timer >= timePerInteract){
            target.GetComponent<IInteractable>().StartInteract();
            timer = 0;
        }
    }

    public void Reset(){    
        if (LeanTween.isTweening(turnKey)){
            LeanTween.cancel(turnKey);
        }
        // LeanTween.rotateY(turnKey, originalYRot, moveDuration);
        LeanTween.rotateLocal(turnKey, new(0f, originalYRot, 0f), moveDuration);
        target.GetComponent<IInteractable>().StopInteract();
        isPressed = false;
    }
}
