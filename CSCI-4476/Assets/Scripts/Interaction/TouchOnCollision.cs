using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TouchOnCollision : MonoBehaviour
{
    void OnCollisionEnter(Collision collision){
        collision.gameObject.GetComponent<ITouchable>()?.OnStartTouch();
    
    }
}
