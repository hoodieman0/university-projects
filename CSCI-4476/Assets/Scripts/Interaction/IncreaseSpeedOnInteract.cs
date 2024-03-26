using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class IncreaseSpeedOnInteract : MonoBehaviour, IInteractable
{
    [SerializeField] float changeSpeed = 5000f;
    float originalSpeed = 2000f;
    MovementController movementController = null;

    public void StartInteract(Interactor interactor){
        if (movementController != interactor.gameObject.GetComponentInParent<MovementController>()){
            movementController = interactor.gameObject.GetComponentInParent<MovementController>();
            
        }
        movementController?.SetSprintSpeed(changeSpeed);

        StartCoroutine(ExampleCoroutine());

        movementController?.SetSprintSpeed(changeSpeed);
        
    }

    IEnumerator ExampleCoroutine()
    {
        //Print the time of when the function is first called.
        Debug.Log("Started Coroutine at timestamp : " + Time.time);

        //yield on a new YieldInstruction that waits for 5 seconds.
        yield return new WaitForSeconds(5);

        //After we have waited 5 seconds print the time again.
        Debug.Log("Finished Coroutine at timestamp : " + Time.time);
    }

    public void WhileInteract(Interactor interactor){

    }
    public void StopInteract(Interactor interactor){
        
    }
}
