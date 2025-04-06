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
    bool movingUp = false;
    bool movingDown = false;

    void Awake(){
        rig = GetComponent<Rigidbody>();
    }
    void OnEnable(){
        InputManager.movement += Move;
        InputManager.moveUpPerformed += MoveUpPerformed;
        InputManager.moveDownPerformed += MoveDownPerformed;
        InputManager.moveUpCanceled += MoveUpCanceled;
        InputManager.moveDownCanceled += MoveDownCanceled;
    }
    

    void Move(Vector2 moveDir){
        this.moveDir = moveDir;
    }

    void MoveUpPerformed(){
        movingUp = true;
    }
    void MoveUpCanceled(){
        movingUp = false;
    }

    void MoveDownPerformed(){
        movingDown = true;
    }
    void MoveDownCanceled(){
        movingDown = false;
    }

    void FixedUpdate(){
        if (moveDir != Vector2.zero && !isLocked){
            rig.AddForce((sprintMultiplier * speed * Time.fixedDeltaTime) * (transform.forward * moveDir.y + transform.right * moveDir.x), ForceMode.Force);
        }
        if (movingUp && !isLocked) rig.AddForce((sprintMultiplier * speed * Time.fixedDeltaTime) * transform.up.normalized, ForceMode.Force);
        if (movingDown && !isLocked) rig.AddForce((sprintMultiplier * speed * Time.fixedDeltaTime) * -transform.up.normalized, ForceMode.Force);
    }

    public void SetSprintSpeed(float s){
        sprintMultiplier = s;
    }
    public float GetSprintSpeed(){
        return sprintMultiplier;
    }

    void OnDisable(){
        InputManager.movement -= Move;
        InputManager.moveUpPerformed -= MoveUpPerformed;
        InputManager.moveDownPerformed -= MoveDownPerformed;
        InputManager.moveUpCanceled -= MoveUpCanceled;
        InputManager.moveDownCanceled -= MoveDownCanceled;
    }
}
