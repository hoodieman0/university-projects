using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioManager : MonoBehaviour
{
    public static AudioManager instance;
    public AudioSource aS;
    void Awake(){
        if (instance == null) {
            instance = this;
            aS = GetComponent<AudioSource>();
        }
        else {
            Destroy(gameObject);
        }
    }
}
