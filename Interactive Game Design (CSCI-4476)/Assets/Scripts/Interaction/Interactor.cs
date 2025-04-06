using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody))]
public class Interactor : MonoBehaviour
{
    [SerializeField]
    float maxDistance = 2f;
    Color rayColor = Color.black;
    IInteractable objBeingLookedAt;
    IInteractable objBeingInteractedWith;

    void OnEnable()
    {
        InputManager.interactAction += Interact;
        InputManager.stopInteractAction += StopInteract;
    }
    void OnDisable()
    {
        InputManager.interactAction -= Interact;
        InputManager.stopInteractAction -= StopInteract;
    }

    void Interact()
    {
        if (objBeingLookedAt != null)
        {
            objBeingLookedAt?.StartInteract(this);
            objBeingInteractedWith = objBeingLookedAt;
        }
    }

    void Update()
    {
        // objBeingInteractedWith?.WhileInteract(this);
    }

    void StopInteract()
    {
        objBeingLookedAt = null;
        objBeingInteractedWith?.StopInteract(this);
        objBeingInteractedWith = null;
    }

    void FixedUpdate()
    {
        // Perform  raycast, stored as hit
        if (Physics.Raycast(transform.position, transform.forward, out RaycastHit hit, maxDistance))
        {
            // If the object has the interface
            if (hit.transform.gameObject.GetComponent<IInteractable>() != null)
            {
                if (rayColor != Color.green)
                {
                    rayColor = Color.green;
                }
                // If the object with the interface is different than last frame
                if (objBeingLookedAt != hit.transform.gameObject.GetComponent<IInteractable>())
                {
                    objBeingLookedAt = hit.transform.gameObject.GetComponent<IInteractable>();
                }
            }
            // If the object does not have the interface
            else
            {
                if (rayColor != Color.red)
                {
                    rayColor = Color.red;
                    objBeingLookedAt = null;
                }
            }
        }
        // If no hit
        else if (rayColor != Color.black)
        {
            rayColor = Color.black;
            objBeingLookedAt = null;
        }
        // Always draw the ray of a certain color
        Debug.DrawRay(transform.position, transform.forward * maxDistance, rayColor);
    }
}
