using System.Collections;
using System.Collections.Generic;
using UnityEditor.ShaderGraph.Internal;
using UnityEngine;
using UnityEngine.AI;

/*
Here's the code for the lever object. 
I believe the only issue was that the rotation, rotX, was not being set properly to 60 on start, 
as C# initializes most variables to 0, rather than setting their initial value to the first newly set value, 
and this can cause issues when using =/+= in Update, an easy thing to miss. 
Best, Phil
*/

public class InteractableLever : MonoBehaviour, IInteractable
{
    [SerializeField] GameObject target;
    [SerializeField] Transform pivot;
    [SerializeField] float speed;
    CameraController cam;
    float mouseY = 0f;
    float rotX = 60f;
    bool leverLock = false;
    float maxX = 60f;
    float minX = -60f;
    float returnTime = 1f;

    void Start(){
        cam = CameraController.instance;
        rotX = transform.localRotation.x;
    }

    public void StartInteract(Interactor _){
        cam.isLocked = true;
        InputManager.mouseLook += MouseDelta;
    }

    void MouseDelta(Vector2 delta){
        mouseY = delta.y;
    }

    void Update(){
        if (mouseY != 0f){
            rotX += mouseY * speed;
            rotX = Mathf.Clamp(rotX, minX, maxX);
            if (rotX == minX && !leverLock){
                leverLock = true;
                PullAction();
            }
            else if (rotX == maxX && leverLock){
                leverLock = false;
            }
        }
    }

    void PullAction(){
        target.GetComponent<IInteractable>().StartInteract();
    }

    public void StopInteract(Interactor _){
        mouseY = 0f;
        cam.isLocked = false;
        InputManager.mouseLook -= MouseDelta;
        LeanTween.rotateX(pivot.gameObject, maxX, returnTime);
        LeanTween.value(rotX, maxX, returnTime).setOnUpdate((float val) => {rotX = val; });
        leverLock = false;
        if (target){
            target.GetComponent<IInteractable>().StopInteract();
        }
    }
}
