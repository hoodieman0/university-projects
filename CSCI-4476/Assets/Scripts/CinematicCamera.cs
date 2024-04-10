using System.Collections;
using System.Collections.Generic;
using Cinemachine;
using UnityEngine;

public class CinematicCamera : MonoBehaviour
{
    public static CinematicCamera instance;
    [SerializeField]    MovementController          moveCon;
    [SerializeField]    CameraController            camCon;
    [SerializeField]    CinemachineVirtualCamera    cineCamera;
    [SerializeField]    Transform                   defaultLookAt;
    [SerializeField]    float                       duration    =   1f;
                        Vector3 originalPosition;
                        
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
        originalPosition = transform.position;
        LockInput(true);
        cineCamera.LookAt = target;

        for(int i = 0; i < dollyLocations.Length; i++){
            LeanTween.move(gameObject, dollyLocations[i].position, duration);
            yield return new WaitForSeconds(duration);
        }
        yield return new WaitForSeconds(duration * 2f);
        cineCamera.LookAt = defaultLookAt;
        cineCamera.gameObject.transform.position = originalPosition;
        LeanTween.move(gameObject, originalPosition, duration);

        LockInput(false);

    }

    void LockInput(bool status){
        camCon.isLocked = status;
        moveCon.isLocked = status;
    }
}
