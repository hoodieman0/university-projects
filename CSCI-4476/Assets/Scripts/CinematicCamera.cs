using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CinematicCamera : MonoBehaviour
{
    public static CinematicCamera instance;
    [SerializeField]    MovementController  moveCon;
    [SerializeField]    CameraController    camCon;
    
                        // Transform           originalPosition;
                        Vector3 originalPosition;
                        Quaternion originalRotation;
                        float               duration;

    void Awake(){
        if (!instance) instance = this;
        else Destroy(gameObject);
    }

    public IEnumerator TriggerCinematic(Transform target, Transform[] dollyLocations){
        // disable inputs
        // set lookat target
        // go to locations one after the other 
        // return to start
        // reenable inputs

        ChangeInputLocks(true);

        for(int i = 0; i < dollyLocations.Length; i++){
            LeanTween.move(gameObject, dollyLocations[i].position, duration);
            yield return new WaitForSeconds(duration);
        }

        ChangeInputLocks(false);

    }

    void ChangeInputLocks(bool status){
        camCon.isLocked = status;
        moveCon.isLocked = status;
    }
}
