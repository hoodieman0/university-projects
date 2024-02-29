using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovementController : MonoBehaviour
{
    [SerializeField]
    Transform cam;
    [SerializeField]
    float sprintMultiplier = 2.0f;
    [SerializeField]
    float speed = 50000.0f;
    Rigidbody rig;
    Vector2 moveDir;
    

    void Awake(){
        rig = GetComponent<Rigidbody>();
    }
   void OnEnable(){
    InputManager.moveAction += Move;
   }

   void Move(Vector2 moveDir){
    this.moveDir = moveDir;
   }

   void FixedUpdate(){
    if (moveDir != Vector2.zero){
        rig.AddForce(speed * sprintMultiplier * Time.fixedDeltaTime * (transform.forward * moveDir.y + transform.right * moveDir.x), ForceMode.Force);   
    }
    }
   
   void OnDisable(){
    InputManager.moveAction -= Move;
   }
}
