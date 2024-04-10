using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovementController : MonoBehaviour
{
    [SerializeField] Transform cam;
    Rigidbody rig;
    Vector2 moveDir = Vector2.zero;
    [SerializeField] float sprintMultiplier = 2f;
    float speed = 50000f;

    public bool isLocked = false;

    void Awake(){
        rig = GetComponent<Rigidbody>();
    }
    void OnEnable(){
        InputManager.movement += Move;
    }
    

    void Move(Vector2 moveDir){
        this.moveDir = moveDir;
    }

    void FixedUpdate(){
        if (moveDir != Vector2.zero && !isLocked){
            rig.AddForce((sprintMultiplier * speed * Time.fixedDeltaTime) * (transform.forward * moveDir.y + transform.right * moveDir.x), ForceMode.Force);
        }
    }

    public void SetSprintSpeed(float s){
        sprintMultiplier = s;
    }
    public float GetSprintSpeed(){
        return sprintMultiplier;
    }

    void OnDisable(){
        InputManager.movement -= Move;
    }
}
