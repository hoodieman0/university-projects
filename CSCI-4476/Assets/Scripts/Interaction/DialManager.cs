using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DialManager : MonoBehaviour, IInteractable
{
    [SerializeField] GameObject dial;
    [SerializeField] GameObject target;
    [SerializeField] float speed;
    CameraController cam;
    float mouseX = 0f;
    float maxRot = 180f;
    float minRot = 0f;
    public float rotY { get; private set; }
    float analogValue = 0f;

    void Start(){
        cam = CameraController.instance;
        rotY = minRot;
    }

    public void StartInteract(Interactor _){
        cam.isLocked = true;
        InputManager.mouseLook += MouseDelta;
    }

    void MouseDelta(Vector2 delta){
        mouseX = delta.x;
    }

    void Update(){
        if (mouseX != 0f){
            rotY += mouseX * speed;
            rotY = Mathf.Clamp(rotY, minRot, maxRot);
            
            if (LeanTween.isTweening(dial)){
                LeanTween.cancel(dial);
            }
            LeanTween.rotateLocal(dial, new(0f, rotY, 0f), .1f);
            
            analogValue = (rotY / maxRot) * 100;
            target.GetComponent<AnalogColorChange>()?.SendAnalogValue(analogValue);
        }
    }

    public void StopInteract(Interactor _){
        mouseX = 0f;
        cam.isLocked = false;
        InputManager.mouseLook -= MouseDelta;

        if (target){
            target.GetComponent<IInteractable>().StopInteract();
        }
    }
}
