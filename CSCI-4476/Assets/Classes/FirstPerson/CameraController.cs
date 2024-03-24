using System.Collections;
using System.Collections.Generic;
// using System.Numerics;
using UnityEngine;

public class CameraController : MonoBehaviour
{
    Vector2 newDir = Vector2.zero;
    [SerializeField]
    float cameraSpeed = 2f;

    void Start(){
        Cursor.lockState = CursorLockMode.Locked;
    }
    void OnEnable(){
        InputManager.mouseLook += MouseLook;
    }

    void MouseLook(Vector2 lookDir){
        newDir += lookDir;
        transform.localRotation = Quaternion.Euler(Mathf.Clamp(-newDir.y * cameraSpeed, -90f, 90f), 0f, 0f);
        transform.parent.localRotation = Quaternion.Euler(0f, newDir.x * cameraSpeed, 0f);
    }

    void OnDisable(){
        InputManager.mouseLook -= MouseLook;
    }
}
