using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tracking : MonoBehaviour
{
    [SerializeField] float speed = 1f;
    [SerializeField] GameObject target = null;
    Vector3 lastKnownPos = Vector3.right;
    Quaternion lookAtRotation;

    void Update(){
        if (!target) return;
        if (lastKnownPos != target.transform.position){
            lastKnownPos = target.transform.position;
            lookAtRotation = Quaternion.LookRotation(lastKnownPos - transform.position);
        }

        if (transform.rotation != lookAtRotation)
            transform.rotation = Quaternion.RotateTowards(transform.rotation, lookAtRotation, speed * Time.deltaTime);
    }

    bool SetTarget(GameObject tar){
        if (tar) return false;
        target = tar;
        return true;
    }
}
