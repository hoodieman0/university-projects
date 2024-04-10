using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour
{
    [SerializeField] float cameraSpeedX = 2f;
    [SerializeField] float cameraSpeedY = 2f;
    Vector2 newDir = Vector2.zero;
    public bool isLocked = false;

    void Start(){
        Cursor.lockState = CursorLockMode.Locked;
    }
    void OnEnable() {
        InputManager.mouseLook += MouseLook;    
    }

    void Update(){
        transform.localRotation = Quaternion.Euler(Mathf.Clamp(-newDir.y * cameraSpeedY, -90f, 90f), 0f, 0f);
        transform.parent.localRotation = Quaternion.Euler(0f, newDir.x * cameraSpeedX, 0f);
    }

    void MouseLook(Vector2 lookDir){
        if(!isLocked){
            newDir += lookDir;
        }
    }

    void OnDisable() {
        InputManager.mouseLook -= MouseLook;  
    }
}
