using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour
{
    [SerializeField] float cameraSpeedX = 2f;
    [SerializeField] float cameraSpeedY = 2f;
    Vector2 newDir = Vector2.zero;
    public Vector2 rotationDir = Vector2.zero;
    public bool isLocked = false;
    public bool rotatingItem = false;
    public GameObject objToRotate;

    void Start(){
        Cursor.lockState = CursorLockMode.Locked;
    }
    void OnEnable() {
        InputManager.mouseLook += MouseLook;    
    }

    void Update(){
        transform.localRotation = Quaternion.Euler(Mathf.Clamp(-newDir.y * cameraSpeedY, -90f, 90f), 0f, 0f);
        transform.parent.localRotation = Quaternion.Euler(0f, newDir.x * cameraSpeedX, 0f);

        if (rotatingItem) objToRotate.transform.rotation = Quaternion.Euler(rotationDir.x * cameraSpeedX, -rotationDir.y * cameraSpeedY, objToRotate.transform.rotation.z);
    }

    void MouseLook(Vector2 lookDir){
        if(!isLocked && !rotatingItem){
            newDir += lookDir;
        }
        else if(rotatingItem){
            rotationDir += lookDir;
        }
    }

    void OnDisable() {
        InputManager.mouseLook -= MouseLook;  
    }
}
